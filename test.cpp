#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
int main() {
    int f = open("user.txt", O_CREAT, 0660);
}