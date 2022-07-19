
#!/bin/bash
MAXNW=128
MUL=128
ITERS=1000

for (( NW=1; NW<=MAXNW; NW++ )); do
    ../src/build/Threads_Implementation $((MUL * NW)) $ITERS $NW 0
done

for (( NW=1; NW<=MAXNW; NW++ )); do
    ../src/build/ff_Implementaion $((MUL * NW)) $ITERS $NW 0
done

for (( NW=1; NW<=MAXNW; NW++ )); do
    ../src/build/Sequential_Implementation $((MUL * NW)) $ITERS 0
done
