# Minishell
A little shell

struct info so far:

t_cmd
*	cmd -> string with the command (ex: echo)
*	flags -> string with flags (ex: -n -a)
* 	intput -> nothing yet. but it will be an array with the fds of 	input files
*	nb_output -> number of fd in which the command export its resule
*	output -> array of ints in which each int is an fd opened and ready to store the result of the command. (ex: output.txt)
*	index -> it is like an id for the structure just in case.
*	next -> the next node to the list, in case there were more than one command with a pipe.
