# EK125Final

> This program takes in internet request data through a web scraper and uses an api to figure out what countries they are coming from.
> The purpose is to find out where the epicenters of attacks are located.

> Needed: Please be connected to the internet and have a C compiler installed for Matlab

> Potential problems:
	Connection timeout to https://liben002.github.io/delete.html. Please visit the webpage to force a wake up and rerun the program
	The data set files have been included in case their is an error in opening/writing/etc.
	API timeout. Please just rerun the program
	If at any time an error is thrown that says to manually run the C program, make sure you have mex working. If the problem persists, run manually, and then rerun 
	the appdesigner.

> In order to ensure that the 100,000 data points are not overwritten, the values are appended instead of written. 

> The API works for 50,000 requests, if you for whatever god forsaken reason end up using all of them, use another key that is provided in the source code.

> The data set was provided by https://www.impactcybertrust.org/ and can be accessed through the means below:

    	Address  : <https://ant.isi.edu/tracedist/uTaXQxOkp/uTaXQxOkp.data>
    	User     : oO2zmTmSh
	Password : XbcjhtKqD
	




