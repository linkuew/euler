/**
 * I regret to admit I cheated slightly for this - I pre-sorted the
 * file using *nix commands. Although sorting a file with over 5000
 * elements sounds like a programming pearl, I admit I was slightly
 * apprehensive about using pointers and quicksort to accomplish this,
 * perhaps this will occur at a later time!
 *
 * Hint: try sed with sort - it should be pretty fast
 *
 * This program should also be pretty fast
 *
 * Also also, I used bash to add the numbers too. Can't really have anything
 * too difficult in C
 *
 * awk '{ print NR*$0 }' [text values here!] | paste -sd+ | bc
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
        char name[1028];
        FILE *in = fopen("data/sorted_names.txt", "r");
        int len = 0;
        int i = 0;
        int total = 0;

        while (fgets(name, 1028, in)) {
                strtok(name, "\n");
                len = strlen(name);
                total = 0;
                for (i = 0; i < len; i++) {
                        total += name[i] - 64;
                }
                printf("%d\n", total);
        }

        // Don't ever forget to free memory, because your computer won't forget
        // what you've done (or rather forgotten to do)
        fclose(in);

        return 0;
}
