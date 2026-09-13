/* Chapter 15, Project 01
 *
 * The `justify` program of 15.3 justifies lines by inserting extra spaces
 * between words. The way `write_line` currently works, the words closer
 * to the end of a line tend to have wider gaps than the words at the 
 * beginning.
 *
 * Improve the program by having `write_line` alternate putting the larger
 * gaps at the end of the line and at the beginning of the line
 */

/* Example output with print_extra_space_now toggle:

  I  need to write a lot of words here so that the program has
  enough  to test.  It takes  a long time but I think I can do
  it. My code will do something, but it won't really alternate
  between  beginning and end of line. It will bump some of the
  spaces  to the  first two  words and  then I  think start to
  favor  the end of the lines. To truly distribute them evenly
  I  would need  to know  how many  tokens are being passed to
  `write_line()`  and the  current structure  does not support
  that.  It is  also possible that the assignment is to change
  line by line, rather than word by word? It's hard to know

 */
