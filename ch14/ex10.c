/* Chapter 14, Exercise 10

   Functions can often, but not always, be written as parameterized macros.
   Discuss what characteristics of a function would make it unsuitable as a
   macro

   Answer:

      Due to the find/replace nature of macros, any parameterized macro that
   takes an incrementing value (++i, or i++) which appears more than once in the
   function is likely to cause unexpected behavior, as the increment will be
   evaluated multiple times in the macro instead of only using the return value
   of the increment in all the locations

 */
