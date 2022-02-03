# X-Ray-Diffractometry
This is a quick and dirty program thrown together to process data from an engineering lab of mine (ENGR M12L). It uses Brigg's angles supplied by an x-ray diffractometer and will use the data to help inform you what the most likely crystal structure of the sample was (out of simple cubic (SC), body-centered cubic (BCC) and face-centered cubic (FCC) crystal structures).

The program takes in a text file containing the data as an argument. The data provided should be the Brigg's angles, not the diffraction angles, and the text file should be populated only with numbers separated by newlines. There is a sample file in the repo containing my lab data.

The program output will have 3 headers, "SC" for simple cubic, "BCC" for body-centered cubic, and "FCC" for face-centered cubic. Underneath those, it will have rows labeled with an integer that have a floating-point number after them. The floats are the errors associated with each calculation. One of the error values in each of the three sections will be red. These are numbers that had the least error for each type of crystal lattice. The best bet is to look at the three red numbers and if the one under, for example, SC is the smallest, then your sample was most likely SC. If you know the sample was *not* SC, then choose the category with the next smallest red number. In the example data file provided, this would lead you to choose FCC.

The program *does not* index the planes or calculate the atomic radius or anything else. I did not have time to implement these features before the lab.

There are ANSI escape codes on lines 110, 111, 116, 117, 122, and 123 to make the text red. If you wish to compile on Windows, you will need to remove or replace those.
