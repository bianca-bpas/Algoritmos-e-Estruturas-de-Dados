#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <algorithm>

namespace fs = std::filesystem;

void run_tests(const std::string& executable, const std::string& test_folder) {
    std::vector<std::string> input_files;

    for (const auto& entry : fs::directory_iterator(test_folder)) {
        if (entry.path().extension() == ".in") {
            input_files.push_back(entry.path().filename().string());
        }
    }

    std::sort(input_files.begin(), input_files.end());
    int passed = 0;
    int total = input_files.size();

    for (const auto& input_file : input_files) {
        std::string test_id = input_file.substr(0, input_file.find_last_of('.'));
        std::string output_file = test_id + ".out";
        std::string input_path = test_folder + "/" + input_file;
        std::string output_path = test_folder + "/" + output_file;
        std::string temp_output = "temp_output.txt";

        // Executa o programa com o caso de teste
        std::ifstream infile(input_path);
        if (!infile) {
            std::cerr << "[!] Não foi possível abrir " << input_path << "\n";
            continue;
        }

        std::ostringstream command;
#ifdef _WIN32
        command << executable << " < " << input_path << " > " << temp_output;
#else
        command << executable << " < " << input_path << " > " << temp_output;
#endif
        int ret_code = std::system(command.str().c_str());
        if (ret_code != 0) {
            std::cerr << "[!] Falha ao executar o programa\n";
            continue;
        }

        // Lê a saída do programa
        std::ifstream temp_outfile(temp_output);
        if (!temp_outfile) {
            std::cerr << "[!] Não foi possível abrir " << temp_output << "\n";
            continue;
        }

        std::ostringstream result_stream;
        result_stream << temp_outfile.rdbuf();
        std::string program_output = result_stream.str();

        // Lê a saída esperada
        std::ifstream outfile(output_path);
        if (!outfile) {
            std::cerr << "[!] Saída esperada para " << test_id << " não encontrada.\n";
            continue;
        }

        std::ostringstream expected_stream;
        expected_stream << outfile.rdbuf();
        std::string expected_output = expected_stream.str();

        // Verifica a saída
        if (program_output == expected_output) {
            std::cout << "[PASS] Teste " << test_id << "\n";
            passed++;
        } else {
            std::cout << "[FAIL] Teste " << test_id << "\n";
            std::cout << "Esperado:\n" << expected_output << "\n";
            std::cout << "Obtido:\n" << program_output << "\n";
        }

        // Remove o arquivo temporário
        std::remove(temp_output.c_str());
    }

    // Resultados finais
    std::cout << "\nResumo: " << passed << "/" << total << " testes passaram.\n";
}

int main() {
    std::string executable_path = "./A_3.exe";  // Substitua pelo caminho do executável
    std::string test_folder_path = "./tests";    // Substitua pelo caminho da pasta de testes

    if (!fs::exists(executable_path)) {
        std::cerr << "[!] Executável não encontrado em: " << executable_path << "\n";
        return 1;
    }

    if (!fs::exists(test_folder_path)) {
        std::cerr << "[!] Pasta de casos de teste não encontrada em: " << test_folder_path << "\n";
        return 1;
    }

    run_tests(executable_path, test_folder_path);
    return 0;
}
