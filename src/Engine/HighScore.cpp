//
// Created by gohts on 14/3/2021.
//

/*

#include <iostream>
#include "../../include/Player.hpp"
#include "../../include/GameMath.hpp"
#include "../../include/Settings.hpp"
#include "../../include/HighScore.hpp"
#include "../../include/GamePanel.hpp"
#include "../../include/Settings.hpp"
#include <fstream>

using namespace Engine;
using namespace Math;


void checkScore(std::string highScore){

    if(player1.getScore() > highScore){
        highScore = PLAYER1.getScore();
    }

    else if (PLAYER2.getScore() > highScore){
        highScore = PLAYER2.getScore();
    }

    createFile(highScore);
}

void fileWrite() {
    int n;
    FILE *FPtr;
    // open file
    FPtr = fopen("highscore.txt", "w+");
    if (FPtr == NULL){
        fprintf(FPtr, "%d", checkScore);
        rewind(FPtr);
    }
    // scan file for integer
    fscanf(FPtr,"%d", &n);

    if (n < PLAYER1.getScore()){
        if(highScore < PLAYER1.getScore()){
            if(end==true){
                fprintf(FPtr, "%d", score);
                rewind(FPtr); // rewind the file, so pointer starts at beginning
                fscanf(FPtr, "%d", &highScore); // scan file for int
            }
        }
    }
}

static void createFile(std::string highScore)
{
    std::ofstream("highscore.txt");

    File scoreFile = new File(FILE_PATH);
    // Create file if not exist
    if (!scoreFile.exists())
    {
        try
        {
            scoreFile.createNewFile();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    // Created a file writer which will store the file to write to
    FileWriter writeFile;
    // Allows us to write to file
    BufferedWriter writer = null;
    try
    {
        // To check if the file exists
        writeFile = new FileWriter(scoreFile);
        // Turn the file into a writing file
        writer = new BufferedWriter(writeFile);
        // Let buffered writer write the high score into file
        writer.write(highScore);
    }
    catch (Exception e)
    {
        // Debug error
        System.out.println(e.toString());
        e.printStackTrace();
    }
    finally
    {
        // Close the writer
        try
        {
            if (writer != null) writer.close();
        }
        catch (Exception e)
        {
            // Debug error
            System.out.println(e.toString());
            e.printStackTrace();
        }
    }
}

static String getHighScore()
{
    // format: Teck Seng: 100
    FileReader readFile;
    BufferedReader reader = null;
    try
    {
        readFile = new FileReader(FILE_PATH);
        reader = new BufferedReader(readFile);
        return reader.readLine();
    }
    catch (Exception e)
    {
        return "No HighScore:0";
    }
    finally
    {
        try
        {
            if (reader != null) reader.close();
        }
        catch (IOException e)
        {
            // Debug error
            System.out.println(e.toString());
            e.printStackTrace();
        }
    }
}

*/