// This struct define the properties of the requested image
typedef struct{
    char* name;
    char* format;
    int q;
    int width;
    int height;
} ImageProperties;

char* modifiedImage(ImageProperties *imgProp);
