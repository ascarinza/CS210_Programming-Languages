# CS210_Programming-Languages


Summarize the project and what problem it was solving.

  The mission of this project was to create a program that analyzed text records recorded by a grocery store. Items were chronologically stored in a text file. The mission of the program was to track how often certain items were purchased so that they could use the information to help rearrange the produce section of the  store.
The program reads in the text file and calculates the frequency of the items and stores the frequencies in a backup file. The program also has 3 menu functions
that allow the user to find the frequency of one item, print the frequencies of all items, or print a chart of all items. When the user is done, they can choose the 4th menu option which exists in the program.



What did you do particularly well?

  In this program, I thought that my approach was done well. My program read an item, created an object of that item, and then either added it to a vector when that item was the first of its kind with frequency one, or just updated the frequency of the item object by +1 if the item was already on the list. I felt that this was a simple and a quick way to store all the items and their frequencies because when I had to find one item I was able to access the item through meme accessor GetName(). This was also able to abstract a lot of the code and keep only the essential parts open to the user.

Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

  One way that I could redo and make this program more efficient would be through the use of maps. The use of maps results in quicker insertion and deletion. In the case of this code that isn't the biggest concern as I just added objects to the end of a vector using push_back which is also quick. Where the maps would make a big the difference is iteration, which is 4-5 times faster than user objects. When writing to the backup file, searching for an item with menu option 1, and iterating through and printing all items in option 2 and 3, this iteration speed using maps would be a good deal more efficient.  
  
  
Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

  I found that there were two parts of this project that took more time than others. The first was the overall structure and figuring out how to design the code itself. I started by writing down all the major functions on paper and then started figuring out the correlations to each other and how they interacted. I then build my header files and started to write that some of the functions would complete. This helped get me started on the right track and it got easier and easier to build off that foundation. 
  
  The second part I had to go back and do a littler refresher on was the try catch blocks for validating the menu input. I was able to remember how it was structured but had some difficulties recalling the exact syntax and how to get my thrown error messages to print to the console. 


What skills from this project will be particularly transferable to other projects or course work?

  I think that branching out and creating separate header and source files was one of the most transferable skills practiced during this project. In larger projects this will be essential and something that is a must learn/do. Other skill such as reading and writing to files was also a good refresher and something that will be useful in work moving forward. 

How did you make this program maintainable, readable, and adaptable?

  I made this program maintainable, readable, and adaptable by building it modulary through the use of header and source files as well as using classes. This program in maintainable and readable as well due to the extensive and detailed in line comments that were left to guide future updates. It is also very adaptable. Wether someone was to read in two input lists, add other variables to the item such as expiration date or cost, it can all be quickly added in the Items class and the main source would never have to be touched also adding to its maintainability and keeping the program relevant and useful. 


