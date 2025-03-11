#Operators
-eq #equal to
-ne #not equal to
-gt #greater than
-lt #less than
-ge #greater and eq to
-le #less and eq to

-d #checks if path is a directory 
-e #if dir exist
-f #checks if path is a file
-w #file has write permission
-x #file has execution permission
-s #if file is not not empty
-L #is a symbolic link


#file handling commands
touch #create a new file
cat #display a file's content
rm #delete a file
cp #copy a file
mv #move a file
echo #write text into a file
>> #append text to a file
grep #search patterns
grep [options] "pattern" file
#options for grep
-i #case intensive search
-v #invert the match dont match the pattern
-c #counts the number of matching lines
-n #show line number of matches
-l #show file name with matching lines
-r #search resursivly in dir
-o #show only matching words not lines
-E #RE for comples patterns


#file permission commands
chmod +x #make file executable
chmod 755 #set permisions
chown # change file owner


#special variables
$0 #script name
$1,$2 # command line argument
$# #number of arguments
$@ #all arguments with seperate value
$* #all arguments as a single string
$$ #process ID of the script
$? #exit status of the last command

#exit status
0 #success
!0 #error or failure

#error handling (set -e)
-e #exit if any command fails
-x #display each command before execution used for debuging
-o pipefail #if any pipeline command fails
