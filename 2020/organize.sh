#!/bin/bash

#rm problem-data -rf
#rm solutions -rf

mkdir -p problem-data;

#for i in A B C D E; do
for i in C; do
    rm $i -rf
    #unzip -o $i.zip
    7z x $i.zip
    sudo chown alex $i -R;
    for t in $(ls $i); do
        mv $i/$t $i/${t:3} #removes unnecesarry prefixes
    done;
    mv $i problem-data
    #rm $i -rf
done;

#mkdir -p solutions;
#rm -rf raw;
#rm -rf sources

#7z x "source.zip";
#mv "source" raw;

#for cityZip in $(ls raw); do
#    rm $city -rf
#    #7z x raw/$cityZip -oraw;
#    city=${cityZip%.zip}
#
#    for group in $(ls raw/$city); do
#        mkdir -p solutions/$group
#
#        for person in $(ls raw/$city/$group); do
#            cp raw/$city/$group/$person solutions/$group/$person-$city -R
#        done;
#    done;
#
#    #rm $city -rf
#done;
##
##rm -rf raw;
