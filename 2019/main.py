import os, subprocess, time, signal, sys, shutil
import csv

MAX_TL = 2
MIN_TL = {
    'A': 0.1,
    'B': 0.1,
    'C': 0.1,
    'D': 0.5,
    'E': 0.5
}
CYRILIC_CITIES = {
    'Blagoevgrad': 'Благоевград', 
    'Burgas': 'Бургас', 
    'Dimitrovgrad': 'Димитровград', 
    'Dobrich': 'Добрич',
    'Gabrovo': 'Габрово',
    'Kazanluk': 'Казанлък', 
    'Kjustendil': 'Кюстендил', 
    'Pazardjik': 'Пазарджик', 
    'Pernik': 'Перник', 
    'Pleven': 'Плевен', 
    'Plovdiv': 'Пловдив',
    'Razgrad': 'Разград', 
    'Ruse': 'Русе',
    'Shumen': 'Шумен',
    'Silistra': 'Силистра',
    'Sliven': 'Сливен',
    'Smolyan': 'Смолян',
    'SofiaNPMG': 'София',
    'SofiaSMG': 'София',
    'Sofia': 'София',
    'StaraZagora': 'Стара Загора',
    'Targovishte': 'Търговище',
    'Troyan': 'Троян',
    'Varna': 'Варна',
    'VarnaMG': 'Варна',
    'Vidin': 'Видин',
    'Vraca': 'Враца',
    'VTarnovo': 'Велико Търново',
    'Yambol': 'Ямбол',
    'Haskovo': 'Хасково',
    'Kardjali': 'Кърджали',
    'Samokov': 'Самоков',
    'Lovech': 'Ловеч'
}
AUTHOR_TL_RATIO = 2
COMPILE_TL = 2
MEMORY_LIMIT = 512 * 1024
BOX_LOC = '/var/local/lib/isolate/0/box/'

Tasks = {}

def list_sorted(path):
    ans = os.listdir(path)
    ans.sort()
    return ans

def compile_source(sourcePath, destPath):
    compileArgs = ['g++', '-O2', '-std=c++11', '-o', destPath, sourcePath]
    try:
        proc = subprocess.Popen(compileArgs, preexec_fn = os.setsid, stdout =
                subprocess.PIPE, stderr = subprocess.PIPE)
        if proc.wait(timeout = COMPILE_TL) != 0:
            #compilation error
            return False
        else:
            return True
    except subprocess.TimeoutExpired:
        return False

def file_cmp(f1, f2):
    text1 = []
    text2 = []
    try:
        with open(f1, 'r') as f:
            text1 = f.read().split()

        with open(f2, 'r') as f:
            text2 = f.read().split()

        return text1 == text2
    except UnicodeDecodeError:
        return False

def run_checker(checker):
    try:
        sandbox_root = BOX_LOC
        shutil.copy(checker, os.path.join(sandbox_root, 'checker'))

        args = ['isolate', '-o', 'score', '-r', 'verdict']
        args.extend(['-t', '10'])
        args.extend(['-m', str(MEMORY_LIMIT)])
        args.extend(['--run', 'checker', 'input', 'answer', 'output'])

        proc = subprocess.Popen(args,
            stdout = subprocess.PIPE,
            stderr = subprocess.PIPE)

        out, err = proc.communicate()
        sandboxMsg = err.decode('utf-8')

        if sandboxMsg[:2] != 'OK':
            print('checker error 2 with ', checker)
            return False

        with open(os.path.join(sandbox_root, 'score')) as f:
            score = float(f.read())

        return score == 1.0

    except (FileNotFoundError, ValueError) as err:
        print('checker error 1 with ', checker, err)
        return False

def run_test(solution, test, task):
    #TODO: should determine the box location from the output here
    subprocess.call(['isolate', '--cleanup'], stdout = subprocess.PIPE)
    subprocess.call(['isolate', '--init'], stdout = subprocess.PIPE)

    subprocess.call(['cp', solution, os.path.join(BOX_LOC, 'solution')])
    subprocess.call(['cp', test['in'], os.path.join(BOX_LOC, 'input')])
    subprocess.call(['cp', test['sol'], os.path.join(BOX_LOC, 'answer')])

    args = ['isolate', '-i', 'input', '-o', 'output', '-t', str(task['tl']), '-m',
            str(MEMORY_LIMIT), '--run', 'solution']

    proc = subprocess.Popen(args, 
            stdout = subprocess.PIPE, 
            stderr = subprocess.PIPE)

    proc.wait()
    out, err = proc.communicate()
    sandboxMsg = err.decode('utf-8')

    if sandboxMsg[:2] != 'OK':
        return {
            'score': 0,
            'time': 'N/A',
            'verdict': 'TL' if sandboxMsg[:4] == 'Time' else 'RE'
        }

    runtime = float(sandboxMsg[4:9])

    okAns = False
    if 'checker' in task:
        okAns = run_checker(task['checker'])
    else:
        okAns = file_cmp(
            os.path.join(BOX_LOC, 'output'),
            os.path.join(BOX_LOC, 'answer')
        )

    if okAns:
        return {
            'score': 1,
            'time': runtime,
            'verdict': 'OK'
        }
    else:
        return {
            'score': 0,
            'time': runtime,
            'verdict': 'WA'
        }

def test_solution(sourcePath, task):
    destPath = sourcePath[:-4]

    res = {
        'compile': True,
        'time': 0,
        'score': 0,
        'verdict': ''
    }

    if not compile_source(sourcePath, destPath):
        res['compile'] = False
        res['time'] = 'N/A'
        res['verdict'] = 'Compilation error'
        return res

    scorePerTest = 100 / len(task['tests'])
    #print(scorePerTest)
 
    for test in task['tests']:
        testRes = run_test(destPath, test, task)
        res['score'] += testRes['score'] * scorePerTest
        res['verdict'] += testRes['verdict'] + ' '

        if testRes['time'] == 'N/A' or res['time'] == 'N/A':
            res['time'] = 'N/A'
        elif testRes['time'] > res['time']:
            res['time'] = testRes['time']

    res['verdict'] = res['verdict'][:-1]
    #print(res)
    return res

def crawl_tasks():
    for group in os.listdir('problem-data'):
        Tasks[group] = {}
        if group == 'A':
            continue

        print(group)
        for task in list_sorted(os.path.join('problem-data', group)):
            print(task)
            Tasks[group][task] = {}
            authorDir = os.path.join('problem-data', group, task, 'author')
            Tasks[group][task]['author'] = os.path.join(authorDir, task + '.cpp')

            checkerSource = os.path.join(authorDir, 'checker.cpp')
            if os.path.isfile(checkerSource):
                checker = os.path.join(authorDir, 'checker')
                compile_source(checkerSource, checker)
                Tasks[group][task]['checker'] = checker

            testPath = os.path.join('problem-data', group, task, 'tests')

            Tasks[group][task]['tl'] = MAX_TL
            Tasks[group][task]['tests'] = []

            for test in list_sorted(testPath):
                if test[-3:] == 'sol':
                    continue

                testNum = int(test.split('.')[-2])
                if (testNum == 0):
                    continue

                outputFile = test[:-2] + 'sol'
                if (not os.path.isfile(os.path.join(testPath, outputFile))):
                    print('Warning {0} exists but {1} not found'.format(test,
                        outputFile))
                    continue
                
                Tasks[group][task]['tests'].append({
                    'in': os.path.join(testPath, test),
                    'sol': os.path.join(testPath, outputFile)
                })

            #continue
            res = test_solution(Tasks[group][task]['author'],
                    Tasks[group][task])

            Tasks[group][task]['tl'] = max(res['time'] * AUTHOR_TL_RATIO,
                    MIN_TL[group])

            print('TL {0}-{1}:  {2}'.format(group, task,
                Tasks[group][task]['tl']))


TestingData = {}

def export_results(group):
    os.makedirs('results', exist_ok = True)
    taskNames = Tasks[group].keys()

    with open(os.path.join('results', group + '.csv'), 'w') as f:
        writer = csv.writer(f)

        header = ['Име', 'Град']
        for task in taskNames:
            header.append(task.capitalize())
        header.append('Точки')

        #print(header)
        writer.writerow(header)

        for participant in TestingData[group]:
            entry = [participant['name'], participant['city']]
            for task in taskNames:
                entry.append(participant[task]['score'])
            entry.append(participant['score'])
            #print(entry)

            writer.writerow(entry)

    with open(os.path.join('results', group + '-extended.csv'), 'w') as f:
        writer = csv.writer(f)

        header = ['име', 'град']
        for task in taskNames:
            header.append(task + '-score')
            header.append(task + '-verdict')
            header.append(task + '-max-time')

        header.append('точки')

        writer.writerow(header)

        for participant in TestingData[group]:
            entry = [participant['name'], participant['city']]
            for task in taskNames:
                entry.append(participant[task]['score'])
                entry.append(participant[task]['verdict'])
                entry.append(participant[task]['time'])
            entry.append(participant['score'])

            writer.writerow(entry)

def test_solutions():
    for group in os.listdir('solutions'):
        TestingData[group] = []

        if group == 'A' or group == 'C':
            continue

        resultCnt = 0

        for participant in os.listdir(os.path.join('solutions', group)):
            entry = {
                'name': participant.split('-')[0],
                'city': CYRILIC_CITIES[participant.split('-')[1]],
                'score': 0
            }
            #print(entry)

            participantDir = os.path.join('solutions', group, participant)

            for taskName, task in Tasks[group].items():
                res = test_solution(os.path.join(participantDir,
                    taskName + '.cpp'), task)
                entry[taskName] = res
                entry['score'] += res['score']
            
            TestingData[group].append(entry)

            print('{0}-{1}: {2}'.format(entry['name'], entry['city'],
                entry['score']))

        TestingData[group].sort(key = lambda x: -x['score'])
        export_results(group)

crawl_tasks()
test_solutions()
