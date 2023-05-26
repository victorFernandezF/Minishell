# Minishell
A little shell

struct info so far:


t_cmd
*	cmd -> string with the command (ex: **<ins>echo</ins>** -n hello world > output_1.txt)
*	nb_cmd -> number of commands.
*	flags -> string with flags ((ex: echo **<ins>-n</ins>** hello world > output_1.txt))
*	params -> array of strings with each param given in the command line. 
((ex: echo -n **<ins>hello</ins><sup>params[0]</sup>** **<ins>world</ins><sup>params[1]</sup>** > output_1.txt))
* 	intput -> last input fd.
*	nb_output -> number of fd in which the command export its results
*	output -> last fd opened and ready to store the result of the command.(ex: output.txt) In bash if you type: *echo "hello" > output_1.txt > output_2.txt* it will open output_1.txt but the result will be stored in output_2.txt and output_1.txt will be empty.
*	index -> it is like an id for the structure.
*	next -> the next node to the list, in case there were more than one command with a pipe.
