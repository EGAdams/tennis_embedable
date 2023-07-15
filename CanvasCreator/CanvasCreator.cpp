#include "CanvasCreator.h"

CanvasCreator::CanvasCreator( RGBMatrix::Options matrix_options, rgb_matrix::RuntimeOptions runtime_opt ) : 
    _matrixOptions( matrix_options ), _runtimeOptions( runtime_opt ) {}

RGBMatrix* CanvasCreator::createCanvas() {
    RGBMatrix* canvas = RGBMatrix::CreateFromOptions( _matrixOptions, _runtimeOptions );
    if (canvas == NULL) {
        printf( "Couldn't create RGBMatrix object.  exiting... \n" );
        exit( 1 ); }

    return canvas; }