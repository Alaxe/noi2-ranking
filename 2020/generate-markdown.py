import os, csv

for group in ['A', 'B', 'C', 'D', 'E']:
    csvFile = open(os.path.join('results', group + '.csv'), 'r')
    csvReader = csv.reader(csvFile)
    mdFile = open(os.path.join('results', group + '.MD'), 'w')

    mdFile.write('| |')
    headerCnt = 1

    for header in csvReader.__next__():
        headerCnt += 1
        mdFile.write(header + '|')
    mdFile.write('\n|')

    for header in range(headerCnt):
        mdFile.write('---|')

    mdFile.write('\n')


    lastPoints = 400
    positon = 0
    count = 0

    for row in csvReader:
        if row[-1] != lastPoints:
            position = count + 1
        lastPoints = row[-1]
        count += 1

        mdFile.write('|{0}|'.format(position))
        for field in row:
            try:
                field = str(round(float(field), 2))
            except ValueError:
                pass
            finally:
                mdFile.write(field + '|')

        mdFile.write('\n')


    csvFile.close()
    mdFile.close()
