#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wurfl.h>

#if IM_VERSION > 6
    #include <MagickWand/MagickWand.h>
#else
    #include <ImageMagick-6/wand/MagickWand.h>
#endif // IM_VERSION

int main()
{
    printf("Hello world!\n");
    printf("%d\n", IM_VERSION);
    return 0;
}
