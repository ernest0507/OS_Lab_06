#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    for (int i = 0; i < n; i++) {
        fork();
        sleep(5);
    }
}

// for the n = 3, the total number of process is 8
/*
explanation: the number of process grows expanentially, so it's like a tree.
after each fork() calling each existing node will have new child.
therefore the number of children doubles
 */
// for the n = 5, the total number of process is 32
/*
The difference is that for n = 5 two additional fork() iterations
are performed, so the number of processes grows from 8 to 32
*/
