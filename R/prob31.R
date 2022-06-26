# To solve the problem, we first consider a smaller subset of the problem:
# How many different ways are there to make 5 pence?
# First, we consider that there are 2 ways to make 2 pence and 1 way
# to make 1 pence, and 1 extra way to make 5 pence, so we should have
# 2 * 2 * 1 + 1 = 5 ways, correct? Well, that unfortunately double-counts
# one method to make 5 pence.

# This program doesn't have much logic. Most of the work was done on scratch
# paper, but hopefully it makes sense by the above logic.


main <- function()
{
        ways <- 0
        coins <- c(1, 2, 5, 10, 20, 50, 100, 200)

        for (i in 1:length(coins)) {
                if (i == 0) {
                        ways <- ways + 1
                        next
                }

                ways_in <- coins[i] / coins[i - 1]
                print(ways_in)
        }

        print(ways)
}

if (!interactive())
{
        main()
}
