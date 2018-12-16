
## Chapter 10: Switch statements 

In C, the switch-statement is actually quite different and is really a jump table. Instead of random Boolean expressions, you can only put expressions that result in integers. These integers are used to calculate jumps from the top of the switch to the part that matches that value.

Switch-statement rules: 
Always include a default: branch so that you catch any missing inputs.
Don't allow fall through unless you really want it. It's also a good idea to add a //fallthrough comment so people know it's on purpose.
Always write the case and the break before you write the code that goes in it.
Try to use if-statements instead if you can.

Remember that there's an if-statement at the top that exits with a return 1; when you don't provide enough arguments. A return that's not 0 indicates to the OS that the program had an error. You can test for any value that's greater than 0 in scripts and other programs to figure out what happened.


What are the four ways he gives to break a switch statement? 
<details> 
* Forget a break, and it'll run two or more blocks of code you don't want it to run.
* Forget a default, and it'll silently ignore values you forgot.
* Accidentally put a variable into the switch that evaluates to something unexpected, like an int, which becomes weird values.
* Use uninitialized values in the switch.
</details> 

## Understanding 

1) write a switch statement that prints out vowels 
2) Explain how the switch statement works 
<details> 
* The compiler marks the place in the program where the switch-statement starts. Let's call this location Y.
* It then evaluates the expression in switch(letter) to come up with a number. In this case, the number will be the raw ASCII code of the letter in argv[1].
* The compiler also translates each of the case blocks like case 'A': into a location in the program that's that far away. So the code under case 'A' is at Y+A in the program.
* It then does the math to figure out where Y+letter is located in the switch-statement, and if it's too far, then it adjusts it to Y+default.
* Once it knows the location, the program jumps to that spot in the code, and then continues running. This is why you have break on some of the case blocks, but not on others.
* If 'a' is entered, then it jumps to case 'a'. There's no break so it falls through to the one right under it, case 'A', which has code and a break.
* Finally, it runs this code, hits the break, and then exits out of the switch-statement entirely.
</details> 

Extra Credit 

1) Write another program that uses math on the letter to convert it to lowercase, and then remove all of the extraneous uppercase letters in the switch.
2) Use the ',' (comma) to initialize letter in the for-loop.
3) Make it handle all of the arguments you pass it with yet another for-loop.
4) Convert this switch-statement to an if-statement. Which do you like better?
5) In the case for 'Y' I have the break outside of the if-statement. What's the impact of this, and what happens if you move it inside of the if-statement. Prove to yourself that you're right


