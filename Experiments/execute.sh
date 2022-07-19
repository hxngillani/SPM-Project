#!/bin/bash

iterations=120
workers=128
size=4096

sizes=(64 512 1024 2048 4096 16384)


echo "testing Threads Implementation with different sizes"
for s in ${sizes[@]}; do
    ../src/build/Threads_Implementation $s $iterations $workers 0
    done


echo "testing Fastflow Implementation with different sizes"
for s in ${sizes[@]}; do
    ../src/build/ff_Implementaion $s $iterations $workers 0
    done


echo "testing Sequential Implementation with different sizes"
for s in ${sizes[@]}; do
    ../src/build/Sequential_Implementation $s $iterations 0
    done



iter=(10 20 40 60 80 100 120)


echo "testing Threads Implementation with different iterations"
for i in ${iter[@]}; do
    ../src/build/Threads_Implementation $size $i $workers 0
    done

echo "testing Fastflow Implementation with different iterations"
for i in ${iter[@]}; do
    ../src/build/ff_Implementaion $size $i $workers 0
    done


echo "testing Sequential Implementation with different iterations"
for i in ${iter[@]}; do
    ../src/build/Sequential_Implementation $size $i 0
    done


echo "testing Threads Implementation with different workers"
for w in {1..128..1}; do
    ../src/build/Threads_Implementation $size $iterations $w 0
    done
echo "testing Fastflow Implementation with different workers"
for w in {1..128..1}; do
 ../src/build/ff_Implementaion $size $iterations $w 0
    done


size=1024

echo "testing Threads Implementation with different workers and large size"
for w in {1..128..1}; do
    ../src/build/Threads_Implementation $size $iterations $w 0
    done
echo "testing Fastflow Implementation with different workers and large size"
for w in {1..128..1}; do
    ../src/build/ff_Implementaion $size $iterations $w 0
    done

echo "testing Sequential Implementation With different Workers and large size"
for w in {1..128..1}; do
    ../src/build/Sequential_Implementation $size $iterations 0
    done



size=4096

echo "testing Threads Implementation with different workers and large size"
for w in {1..128..1}; do
    ../src/build/Threads_Implementation $size $iterations $w 0
    done
echo "testing Fastflow Implementation with different workers and large size"
for w in {1..128..1}; do
    ../src/build/ff_Implementaion $size $iterations $w 0
    done

echo "testing Sequential Implementation With different Workers and large size"
for w in {1..128..1}; do
    ../src/build/Sequential_Implementation $size $iterations 0
    done


size=16384

echo "testing Threads Implementation with different workers and large size"
for w in {1..128..1}; do
    ../src/build/Threads_Implementation $size $iterations $w 0
    done
echo "testing Fastflow Implementation with different workers and large size"
for w in {1..128..1}; do
    ../src/build/ff_Implementaion $size $iterations $w 0
    done

echo "testing Sequential Implementation With different Workers and large size"
for w in {1..128..1}; do
    ../src/build/Sequential_Implementation $size $iterations 0
    done

echo "Running 20 Times Each Implemntation with 1-128 Workers on Size 16384 to get an Average Time"

workers=(1 2 4 8 16 32 64 128)
for w in ${workers[@]}; do
    for i in {1..10}; do  ../src/build/Threads_Implementation $size $iterations $w 0
    done
    for i in {1..10}; do  ../src/build/ff_Implementaion $size $iterations $w 0
    done
done
for i in {1..10}; do  ../src/build/Sequential_Implementation $size $iterations 0
done