import os
import subprocess

def run_tests(executable, test_folder):
    """
    Automatiza o teste de um programa para casos de teste especificados em arquivos.

    Args:
        executable (str): Caminho para o executável do programa.
        test_folder (str): Caminho para a pasta contendo os casos de teste.

    Returns:
        None: Os resultados dos testes são exibidos no console.
    """
    input_files = sorted([f for f in os.listdir(test_folder) if f.endswith('.in')])
    passed = 0
    total = len(input_files)

    for input_file in input_files:
        test_id = input_file.split('.')[0]
        output_file = f"{test_id}.out"

        input_path = os.path.join(test_folder, input_file)
        output_path = os.path.join(test_folder, output_file)

        # Executa o programa com o caso de teste
        with open(input_path, 'r') as infile:
            result = subprocess.run([executable], stdin=infile, capture_output=True, text=True)

        # Lê a saída esperada
        if not os.path.exists(output_path):
            print(f"[!] Saída esperada para {test_id} não encontrada.")
            continue

        with open(output_path, 'r') as outfile:
            expected_output = outfile.read().strip()

        # Verifica se a saída do programa está correta
        program_output = result.stdout.strip()

        if program_output == expected_output:
            print(f"[PASS] Teste {test_id}")
            passed += 1
        else:
            print(f"[FAIL] Teste {test_id}")
            print(f"Esperado:\n{expected_output}")
            print(f"Obtido:\n{program_output}")

    # Resultados finais
    print(f"\nResumo: {passed}/{total} testes passaram.")

if __name__ == "__main__":
    # Caminho para o executável e a pasta com os testes
    executable_path = "./A_3.exe"  # Substitua pelo caminho do executável
    test_folder_path = "./tests"  # Substitua pelo caminho da pasta com casos de teste

    if not os.path.exists(executable_path):
        print(f"[!] Executável não encontrado em: {executable_path}")
    elif not os.path.exists(test_folder_path):
        print(f"[!] Pasta de casos de teste não encontrada em: {test_folder_path}")
    else:
        run_tests(executable_path, test_folder_path)
