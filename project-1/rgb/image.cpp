#include <rgb/image.hpp>

namespace rgb {
    image::image(int w, int h, const color& fill) {
        assert(h > 0 && w > 0);
        iwidth = w;
        iheight = h;
        pixels = new color*[w];
        color *data = new color[h*w];
        for(int i = 0 ; i < w ; i++){
            pixels[i] = data + i * h;
            for(int j = 0 ; j < h ; j++){
                pixels[i][j] = fill;
            }
        }
    }

    image::~image() {
        delete [] pixels[0];
        delete [] pixels;
    }

    int image::width() const {
        return iwidth;
    }

    int image::height() const {
        return iheight;
    }

    color& image::at(int x, int y) {
        return pixels[x][y];
    }

    const color& image::at(int x, int y) const {
        return pixels[x][y];
    }

    void image::invert() {
        for(int i = 0 ; i < iwidth ; i++){
            for(int j = 0 ; j < iheight ; j++){
                pixels[i][j].invert();
            }
        }
    }

    void image::to_gray_scale() {
        for(int i = 0 ; i < iwidth ; i++){
            for(int j = 0 ; j < iheight ; j++){
                pixels[i][j].to_gray_scale();
            }
        }
    }

    void image::fill(int x, int y, int w, int h, const color& c) {
        for(int i = 0 ; i < iwidth ; i++){
            for(int j = 0 ; j < iheight ; j++){
                if(i >= x && i < (x + w)){
                    if(j >= y && j < (y + h)){
                        pixels[i][j] = c;
                    }
                }
            }
        }
    }

    void image::replace(const color& a, const color& b) {
        for(int i = 0 ; i < iwidth ; i++){
            for(int j = 0 ; j < iheight ; j++){
                if(pixels[i][j] == a){
                    pixels[i][j] = b;
                }
            }
        }
    }

    void image::add(const image& img, const color& neutral, int x, int y) {
        for(int i = x, i2 = 0 ; i < iwidth, i2 < img.iwidth ; i++, i2++){
            for(int j = y, j2 = 0 ; j < iheight , j2 < img.iheight ; j++, j2++){
                if(img.at(i2,j2) != neutral){
                    pixels[i][j] = img.at(i2,j2);
                }
            }
        }
    }

    void image::crop(int x, int y, int w, int h) {
        //processo para copia da matriz anterior e alocação de uma nova
        color** aux = pixels;
        pixels = new color*[w];
        color *data = new color[h*w];
        for(int i = 0 ; i < w ; i++){
            pixels[i] = data + i * h;
            for(int j = 0 ; j < h ; j++){
                pixels[i][j] = color::WHITE;
            }
        }
        //processo de preenchimento da nova matriz
        for(int i = x, i2 = 0  ; i < iwidth && i2 < w ; i++, i2++){
            for(int j = y, j2 = 0 ; j < iheight && j2 < h ; j++, j2++){
                pixels[i2][j2] = aux[i][j];
            }
        }
        delete [] aux[0];
        delete [] aux;
        iwidth = w;
        iheight = h;
    }

    void image::rotate_right(){
        //criação e inicialização de aux
        int auxheight = iwidth;
        int auxwidth = iheight;
        color** aux = new color*[auxwidth];
        color *data = new color[auxheight*auxwidth];
        for(int i = 0 ; i < auxwidth ; i++){
            aux[i] = data + i * auxheight;
            for(int j = 0 ; j < auxheight ; j++){
                aux[i][j] = color::WHITE;
                //não alterei aqui os valores porque para mim ficava mais explicito fazer como fiz no próximo passo
            }
        }
        //resultado da rotação de pixels fica em aux
        for(int i = 0 ; i < iwidth ; i++){
            for (int j = 0; j < iheight; j++){
                aux[iheight-j-1][i] = pixels[i][j];
            }
        }
        //criação e inicialização da nova matriz principal
        delete [] pixels[0];
        delete [] pixels;
        iwidth = auxwidth;
        iheight = auxheight;
        pixels = new color*[iwidth];
        color *data2 = new color[iheight*iwidth];
        for(int i = 0 ; i < iwidth ; i++){
            pixels[i] = data2 + i * iheight;
            for(int j = 0 ; j < iheight ; j++){
                pixels[i][j] = aux[i][j];
            }
        }
        //eliminação do espaço alocado para aux
        delete [] aux[0];
        delete [] aux;
    }

    void image::rotate_left(){
        //criação e inicialização de aux
        int auxheight = iwidth;
        int auxwidth = iheight;
        color** aux = new color*[auxwidth];
        color *data = new color[auxheight*auxwidth];
        for(int i = 0 ; i < auxwidth ; i++){
            aux[i] = data + i * auxheight;
            for(int j = 0 ; j < auxheight ; j++){
                aux[i][j] = color::WHITE;
                //não alterei aqui os valores porque para mim fica mais explicito fazer como fiz no próximo passo
            }
        }
        //resultado da rotação de pixels fica em aux
        for(int i = 0 ; i < iwidth ; i++){
            for (int j = 0; j < iheight; j++){
                aux[j][iwidth-i-1] = pixels[i][j];
            }
        }
        //criação e inicialização da nova matriz principal
        delete [] pixels[0];
        delete [] pixels;
        iwidth = auxwidth;
        iheight = auxheight;
        pixels = new color*[iwidth];
        color *data2 = new color[iheight*iwidth];
        for(int i = 0 ; i < iwidth ; i++){
            pixels[i] = data2 + i * iheight;
            for(int j = 0 ; j < iheight ; j++){
                pixels[i][j] = aux[i][j];
            }
        }
        //eliminação do espaço alocado para aux
        delete [] aux[0];
        delete [] aux;
    }

    void image::mix(const image& img, int factor) {
        for(int i = 0 ; i < iwidth ; i++){
            for(int j = 0 ; j < iheight ; j++){
                pixels[i][j].mix(img.at(i,j),factor);
            }
        }
    }
}
