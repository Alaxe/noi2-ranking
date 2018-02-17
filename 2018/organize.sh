#!/bin/bash

#rm problem-data -rf
#rm solutions -rf

#mkdir -p problem-data;

for i in D E; do
#    rm $i -rf
    unzip -o $i.zip
    sudo chown alex $i -R;
    for t in $(ls $i); do
        mv $i/$t $i/${t:3} #removes unnecesarry prefixes
    done;
    mv $i problem-data
    #rm $i -rf
done;

#mkdir -p solutions;
#rm -rf raw;
#rm -rf raboti_na_uchastnicite
#
#unzip raboti_na_uchastnicite.zip;
#mv raboti_na_uchastnicite raw;
#
#for cityZip in $(ls raw); do
#    rm $city -rf
#    unzip raw/$cityZip;
#    city=${cityZip%.zip}
#
#    #for group in $(ls raw/$city); do
#    #    mkdir -p solutions/$group
#
#    #    for person in $(ls raw/$city/$group); do
#    #        cp raw/$city/$group/$person solutions/$group/$person-$city -R
#    #    done;
#    #done;
#
#    rm $city -rf
#done;
#
#rm -rf raw;
