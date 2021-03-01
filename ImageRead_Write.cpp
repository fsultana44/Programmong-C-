
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>

#define BUFFER_IMAGE "Image_buffer.txt"
using namespace std;

/*
    FUNCTION PROTOTYPES
*/

// Call back function
void onDataCallback(unsigned short* dataPtr, int width, int height);

// Read image from buffer (text file)
void readImage(unsigned short **imgData, int height, int width);

// Write image to buffer (text file)
void writeImage(unsigned short **imgData, int height, int width);

/**********************************  Main function********************************************************/
int main(int argc, char *argv[])
{

    // This function needs two arguments(height,width)

    //Declaring variables
    int height=512;
    int width =640;
    unsigned short *image;
    unsigned short **image2D;


    // Allocate memory for the image
    image = new unsigned short[height*width];

    // Call 'onDataCallback' to get the image
    onDataCallback(image, width, height);

#if (0)// To print 1D image change it to 1
    for(int i=0; i < height*width; i++)
        cout << image[i] << ",";

    cout << endl;
#endif

    //Converting the image to 2D image.
    image2D = new unsigned short*[height];

    {
        int row=0;
        for(int idx=0; idx<height*width; idx+=width)
        {
            // Allocate width size array
            image2D[row] = new unsigned short[width];
            // 'memcpy'is used to copy data from 1D array to 2D array.
            memcpy(image2D[row], &image[idx], width*sizeof(unsigned short));
            row++;
        }
    }

    // No need to 1D image from now on
    delete image;
    
  //For 2D Image

#if 0 //To print 2d image change this to 1
    
    for(int h=0; h < height ; h++)
    {
        cout << "Row: " << h << endl;
        for(int w=0; w < width; w++)
        {
           cout << image2D[h][w] << ", " ;
        }
        cout << endl;
    }
#endif





#if 1 // To print 2d Image change it to 1
    
    for(int h=0; h < height ; h++)
    {
        cout << "Row: " << h << endl;
        for(int w=0; w < width; w++)
        {
            cout << image2D[h][w] << ", " ;
        }
        cout << endl;
    }
#endif


    // Deleting 2d image
    for(int h=0; h < height ; h++)
        delete image2D[h];
    delete image2D;

    return 0;
}


// This function will be automatically called by an imaginary SDK (from its own thread).

void onDataCallback(unsigned short* dataPtr, int width, int height)
{
    
    if((width%2) != 0)
    {
        cerr << "DataCallback will remain valid when width dividable by 2\n" << endl; 
    }
   
    if((height%2) != 0)
    {
       cerr << "DataCallback will remain valid when height dividable by 2\n" << endl; 
    }

    // Filling up the image pointer (treated as 1D array)
    for(int i=0; i < (height*width); i++)
    {
        // using random numbers maximum 65535 for 16-bit values
        dataPtr[i] = (unsigned)rand() % 65535;
    }

    return;
}

void readImage(unsigned short **imgData, int height, int width)
{
    ifstream inputFile; //Stream class to read input-file
    string line;

    inputFile.open(BUFFER_IMAGE);

    int h=0;
    int w=0;
    
    while (getline(inputFile, line, ','))
    {
        if (line == "\n")
        {
            h++;
            w=0;
            line.erase(0);
        }
        if(line.size() > 0 && (h<height) && (w<width))
        {
            imgData[h][w] = (unsigned short)stoi(line);
            w++;
        }
    }

    inputFile.close();

}

void writeImage(unsigned short **imgData, int height, int width)
{
    
    ofstream outputFile; //Stream class to write on file

    outputFile.open(BUFFER_IMAGE);

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            outputFile << imgData[h][w] << ",";
        }
        outputFile << "\n";
    }
    outputFile.close();

    return;
}


