//! @file color.hpp
#ifndef __rgb_color_hpp__
#define __rgb_color_hpp__

#include <iostream>

namespace rgb {
    typedef unsigned char rgb_value;

    class color {
    private:
        //! Campo para guardar a componente red de uma color
        rgb_value r;
        //! Campo para guardar a componente green de uma color
        rgb_value g;
        //! Campo para guardar a componente blue de uma color
        rgb_value b;
    public:
        //! Constante que representa a cor vermelha
        //!
        //! \return rgb::color red
        static const color RED;
        //! Constante que representa a cor verde
        //!
        //! \return rgb::color green
        static const color GREEN;
        //! Constante que representa a cor azul
        //!
        //! \return rgb::color blue
        static const color BLUE;
        //! Constante que representa a cor preta
        //!
        //! \return rgb::color black
        static const color BLACK;
        //! Constante que representa a cor branca
        //!
        //! \return rgb::color white
        static const color WHITE;
        //! Construtor de uma cor por omissão
        //!
        //! inicializa todas as componentes RGB com valor 0
        color();
        //! Construtor de uma cor por cópia de outra
        //!
        //! \param c cor a copiar
        color(const color& c);
        //! Construtor que usa valores fornecidos para inicializar as componentes RGB
        //!
        //! \param r componente red
        //! \param g componente green
        //! \param b componente blue
        color(rgb_value r, rgb_value g, rgb_value b);
        //! Obtem valor para a componente red
        //!
        //! \return valor da componente red
        rgb_value red() const;
        //! Obtem referência para a componente red
        //!
        //! \return referência da componente red
        rgb_value& red();
        //! Obtem valor para a componente green
        //!
        //! \return valor da componente green
        rgb_value green() const;
        //! Obtem referência para a componente green
        //!
        //! \return referência da componente green
        rgb_value& green();
        //! Obtem valor para a componente blue
        //!
        //! \return valor da componente blue
        rgb_value blue() const;
        //! Obtem referência para a componente blue
        //!
        //! \return referência da componente blue
        rgb_value& blue();
        //! Operador de atribuição
        //!
        //! \param c cor a igualar
        //! \return rgb::color
        color& operator=(const color& c);
        //! Operador de igualdade
        //!
        //! \param c cor a comparar
        //! \return booleano '0' ou '1'
        bool operator==(const color &c) const;
        //! Operador de desigualdade
        //!
        //! \param c cor a comparar
        //! \return booleano '0' ou '1'
        bool operator!=(const color &c) const;
        //! Função para inverter a cor
        void invert();
        //! Função para converter a cor para uma escala de cinzento
        void to_gray_scale();
        //! Função para misturar duas cores com um fator
        //!
        //! \param c segunda cor
        //! \param f fator
        void mix(const color& c, int f);
    };
}
#endif
