
rm sourceByGroup -Rf

for city in $(ls source); do
    if [ "$city" = "None" ]; then
        continue;
    fi;
    for group in $(ls source/$city); do
        mkdir -p solutions/$group

        for person in $(ls source/$city/$group); do
            cp source/$city/$group/$person solutions/$group/$person-$city -R
        done;
    done;
done;
