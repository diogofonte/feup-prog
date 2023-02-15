//! @file image.hpp
#ifndef __rgb_image_hpp__
#define __rgb_image_hpp__
#include <cassert>
#include <rgb/color.hpp>

namespace rgb {
    class image {
    private:
        //! Campo para guardar a largura da imagem
        int iwidth;
        //! Campo para guardar a altura da imagem
        int iheight;
        //! Campo para guardar os pixeis da imagem
        //!
        //! matriz de cores implementada como array de apontadores
        color **pixels;
    public:
        //! Construtor de imagem
        //!
        //! \param w largura
        //! \param h altura
        //! \param fill cor inical para todos os pixeis (por defeito é a cor branca)
        image(int w, int h, const color& fill = color::WHITE);
        //! Destrutor de imagem
        //!
        //! liberta o espaço alocado para a matriz de pixeis
        ~image();
        //! Obtem a largura da imagem
        //!
        //! \return iwidth
        int width() const;
        //! Obtem a altura da imagem
        //!
        //! \return iheight
        int height() const;
        //! Obtem cor do pixel na posição (x,y)
        //!
        //! \param x componente x da posição
        //! \param y componente y da posição
        //! \return referência mutável para a cor do pixel
        color& at(int x, int y);
        //! Obtem cor do pixel (constante) na posição (x,y)
        //!
        //! \param x componente x da posição
        //! \param y componente y da posição
        //! \return referência constante para a cor do pixel
        const color& at(int x, int y) const;
        //! Função para inverter todos os pixeis da imagem
        //!
        //! utiliza a função color::invert()
        void invert();
        //! Função para converter todos os pixeis para uma escala de cinzento
        void to_gray_scale();
        //! Função para alterar a cor de pixeis com uma certa cor
        //!
        //! \param a cor a substituir
        //! \param b cor substituta
        void replace(const color& a, const color& b);
        //! Função para desenhar um retângulo na imagem
        //!
        //! \param x componente x do topo superior esquerdo
        //! \param y componente y do topo superior esquerdo
        //! \param w largura do retêngulo
        //! \param h altura do retângulo
        //! \param c cor do retângulo
        void fill(int x, int y, int w, int h, const color& c);
        //! Função para alterar a imagem
        //!
        //! mistura cada pixel com o pixel correspondente em img com um fator
        //! utiliza a função color::mix()
        //! \param img imagem a misturar
        //! \param factor fator a misturar
        void mix(const image& img, int factor);
        //! Função para reduzir a imagem
        //!
        //! reduz a dimensão ao retângulo com início (x,y) e dimensão w * h
        //! \param x componente x do topo superior esquerdo
        //! \param y componente y do topo superior esquerdo
        //! \param w largura
        //! \param h altura
        void crop(int x, int y, int w, int h);
        //! Função para rodar a imagem para a esquerda
        void rotate_left();
        //! Função para rodar a imagem para a direita
        void rotate_right();
        //! Função para adicionar o conteúdo de img à imagem
        //!
        //! substitui os pixeis a partir da posição (x,y) exceto quando o pixel em img tem cor neutral
        //! \param img imagem a adicionar
        //! \param neutral cor para conparação
        //! \param x componente x da posição inicial
        //! \param y componente y do posição inicial
        void add(const image& img, const color& neutral, int x, int y);
    };
}


#endif
