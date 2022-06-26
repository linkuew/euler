# Converting a length of text into a number should be fairly easy, but R has some
# oddities that make this somewhat interesting to do. However, we should ask, how
# to compare the number representing a word to triangle number?

# This could be done by looking at the longest word, and assuming it comprised of
# only Zs, and merely generate the triangle numbers only up to this number, and
# merely adjust is needed. We could also, however, come up with a closed form
# solution to generating triangle numbers, and check them on the fly if we wanted...

library(stringr)

main <- function()
{
        tri_words = 0
        word_file <- file("./data/p042_words.txt", "r")

        line <- readLines(word_file)

        words <- unlist(str_split(line, ','))

        for (word in words) {
                word <- str_replace_all(word, "\"", "")

                letters <- str_split(word, "")[[1]]
                total <- 0
                        for (letter in letters) {
                                total <- total + (utf8ToInt(letter) - 64)
                        }

                if ((1/2)*(-1 + sqrt(8*total + 1)) %% 1 == 0) {
                        tri_words <- tri_words + 1
                }
        }

        print(tri_words)
}

if (!interactive())
{
        main()
}
