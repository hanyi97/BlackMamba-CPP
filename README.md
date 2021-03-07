
# Black Mamba
This is a multiplayer snake game coded in C++ for ICT1009 project.

## Git Guide
### Project set up steps:
1. Clone project  
   ```git clone https://github.com/hanyi97/BlackMamba-CPP.git```

1. Checkout master branch  
   ```git checkout master```

1. Create and checkout branch  
   ```git checkout -b <branchname>```

1. Push your branch to GitHub  
   ```git push -u origin <branchname>```

### Basic workflow:
1. Checkout your branch  
   ```git checkout <branchname>```

1. Code and test your code

2. Stage your changes to the branch (best practice to add the files that you modified only)  
   ```git add <file name>```

4. Commit your changes  
   ```git commit -m “<commit message>”```  
   or  
   ```git commit``` Press enter and type the summary and description for the commit. Then press esc and type :wq

5. Push your changes to Github  
   ```git push```

### Get updates from master branch to your own branch:
1. Check out master branch  
   ```git checkout master```

2. Pull updates from remote master branch to local master branch    
   ```git pull```

3. Change back to your branch  
   ```git checkout <branchname>```

4. Merge master branch code to your branch  
   ```git merge master```

### Once your feature is completed, merge it to master branch:
You can create a pull request in Github to merge your branch to master branch

#### OR
1. Checkout master branch  
   ```git checkout master```

2. Merge your branch to master branch  
   ```git merge <branchname>```

3. Push merged code to master branch in Github  
   ```git push```

**Note: Best practice to commit your changes regularly**