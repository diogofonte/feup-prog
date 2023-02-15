
//! @file script.hpp
#ifndef __rgb_script_hpp__
#define __rgb_script_hpp__

#include <fstream>
#include <rgb/image.hpp>

namespace rgb {
    class script {
    private:
        //! Função para preencher uma imagem a partir da posição (x,y) com uma cor
        //! através do uso da função membro image::fill()
        void fill();
        //! Função para inicializar uma certa imagem
        void open();
        //! Função para criar e preencher uma imagem com uma cor
        //! através do uso do construtor de imagem
        void blank();
        //! Função para guardar uma certa imagem png
        void save();
    public:
        //! Construtor de um script
        //!
        //! \param filename string com o nome do ficheiro para ler o script
        script(const std::string& filename);
        //! Destrutor de um script
        //!
        //! liberta o espaço alocado para o script
        ~script();
        //! Função para processar os vários comandos presentes num script
        void process();
    private:
        //! Campo para guardar a imagem principal
        image* img;
        //! Campo para guardar o objeto de input
        std::ifstream input;
        //! Campo para guardar o diretório do input
        std::string root_path;
    };
}
#endif
