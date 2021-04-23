#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ImageMagick-6/wand/MagickWand.h>
#include "ImageController.h"
#define FOLDER "cache/"

MagickWand *m_wand = NULL;

char* modifiedImage(ImageProperties* imgProp){

    // Initialize MagickWand
	MagickWandGenesis();
	m_wand = NewMagickWand();

	// Read the image
	MagickReadImage(m_wand, imgProp->name);

	// Modify image based on imgProp params
    if(imgProp->q != 0)
        MagickSetImageCompressionQuality(m_wand, imgProp->q);
    if(imgProp->height != 0 && imgProp->width != 0)
        MagickResizeImage(m_wand, imgProp->width, imgProp->height, LanczosFilter, 1);

    // Create new random name for the modified image
    srand(time(NULL));
    int randInt = rand();
    char* modifiedImageName = malloc(sizeof(int));

    sprintf(modifiedImageName, "%d", randInt);

    // Create the path name to store the image
    char* pathName = malloc(sizeof(FOLDER) + sizeof(modifiedImageName) + 1);
    sprintf(pathName, "%s", FOLDER);

    strcat(pathName, modifiedImageName);

     // Store new image
    MagickWriteImage(m_wand, pathName);

    // Destroy MagickWand
    if(m_wand)m_wand = DestroyMagickWand(m_wand);
	MagickWandTerminus();

    return modifiedImageName;
}
