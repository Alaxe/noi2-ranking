#!/bin/bash

#rm problem-data -rf
#rm solutions -rf

#mkdir -p problem-data;

#mkdir -p solutions;
#rm -rf raw;
#rm -rf raboti_na_uchastnicite
#
#unzip raboti_na_uchastnicite.zip;
#mv raboti_na_uchastnicite raw;
#

#for i in A B C D E; do
#    rm $i -rf;
#    mkdir $i;
#done;

for g in A B C D E; do
    for d in $(ls -d $g/*-shumen); do
        echo $d;
        mv $d "${d/shumen/Shumen}";
    done;
    for d in $(ls -d $g/*-GABROVO); do
        echo $d;
        mv $d "${d/GABROVO/Gabrovo}";
    done;

done;

#for cityZip in $(ls raw); do
#    sudo rm $city -rf
#    unzip -q raw/$cityZip;
#    city=${cityZip%.zip}
#    echo $city;
#    sudo chown -R alex $city
#
#    #rm $city -rf
#
#    for group in $(ls $city); do
#        mkdir -p $group
#
#        for person in $(ls $city/$group); do
#            cp $city/$group/$person $group/$person-$city -R
#        done;
#    done;
#
#    #rm $city -rf
#done;
