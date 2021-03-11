
# Black Mamba
This is a multiplayer snake game coded in C++ for ICT1009 project.

## Git Guide
### Project set up steps:
1. Clone project  
   ```git clone https://github.com/hanyi97/BlackMamba-CPP.git```

1. Checkout main branch  
   ```git checkout main```

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

### Get updates from main branch to your own branch:
1. Check out main branch  
   ```git checkout main```

2. Pull updates from remote main branch to local main branch    
   ```git pull```

3. Change back to your branch  
   ```git checkout <branchname>```

4. Merge main branch code to your branch  
   ```git merge main```

### Once your feature is completed, merge it to main branch:
You can create a pull request in Github to merge your branch to main branch

**Note: Best practice to commit your changes regularly**

### Naming conventions:
**Class/Header:** Hello.cpp/Hello.hpp, HelloWorld.cpp/HelloWorld.hpp  
**Methods:** hello(), helloWorld()  
**Variables:** hello, helloWorld  
**Constants:** HELLO, HELLO_WORLD  
