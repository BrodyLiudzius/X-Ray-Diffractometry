# X-Ray-Diffractometry
This is a quick and dirty program thrown together to process data from an engineering lab of mine (ENGR M12L at Moorpark College). It uses Brigg's angles supplied by an x-ray diffractometer to help inform you what the most likely crystal structure of the sample was (out of simple cubic (SC), body-centered cubic (BCC) and face-centered cubic (FCC) crystal structures).

Here's a good powerpoint slide on the subject:
https://www.unf.edu/~michael.lufaso/chem4627/ch2_solid_state.pdf

The program takes in a single argument—a text file containing the required data. The data provided should be the Brigg's angles—not the diffraction angles—and the text file should be populated only with numbers separated by newlines. There is an `angles.txt` sample file in the repo that contains my lab data. The command to run it is simply `py ./main.py ./angles.txt`

The program output will have 3 headers, "SC" for simple cubic, "BCC" for body-centered cubic, and "FCC" for face-centered cubic. Underneath those, it will have rows labeled with an integer that has a floating-point number after them. The floats are the errors associated with each calculation. One of the error values in each of the three sections will have a star next to it. These are numbers that had the least error for each type of crystal lattice. The best bet is to look at the three red numbers and if the one under, for example, SC is the smallest, then your sample was most likely SC. If you know the sample was *not* SC, then choose the category with the next smallest red number. In the example data file provided, this would lead you to choose FCC.

The program *does not* index the planes or calculate the atomic radius or anything else.