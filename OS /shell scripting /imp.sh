#Operator conditions
-eq #equal to
-ne #not equal to
-gt #greater than
-lt #less than
-ge #greater and eq to
-le #less and eq to

#file handling commands
touch #create a new file
cat #display a file's content
rm #delete a file
cp #copy a file
mv #move a file
echo #write text into a file
>> #append text to a file

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
