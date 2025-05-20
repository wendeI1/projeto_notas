# 📚 Sistema de Gerenciamento de Notas em C

Este projeto é um sistema simples feito em C para gerenciar notas de alunos. Ele permite o cadastro, atualização, consulta e exclusão de informações, com foco em praticidade e organização no terminal.

---

## ✅ Funcionalidades

- 📌 Cadastro de alunos com RGM único
- 🧾 Consulta de todos os alunos cadastrados
- 🔎 Busca individual de aluno por RGM
- ✏️ Inserção e atualização das notas A1, A2 e AF
- 🧮 Cálculo da média e situação do aluno
- 🗑️ Exclusão de notas ou de um aluno por completo
- 📤 Exportação dos dados
- 📘 Menu interativo no terminal

---

## 🧠 Lógica de Aprovação

- A1 e A2 variam de 0 a 5 (peso igual)
- Média mínima para aprovação direta: **6.0**
- Se média < 6, o aluno precisa da **AF (Avaliação Final)**
- Notas são inicializadas em `-1`

---

## 🛠️ Tecnologias

- Linguagem: **C**
- Compilador sugerido: `gcc`
- Plataforma: **Console / Terminal**

---

## 📂 Estrutura dos Arquivos

```plaintext
📁 Projeto/
├── LICENSE                 # Licença MIT
├── projeto_notas.c         # Arquivo principal com o menu e chamadas de função
├── README.md               # Este arquivo
```
---

## ⚠️ Avisos
1)
Este projeto foi desenvolvido por mim, Wendel, durante o meu primeiro semestre do curso de Ciência da Computação.
Ainda estou aprendendo os fundamentos da linguagem C e começando a usar o GitHub, então é possível que o código contenha falhas, más práticas ou esteja em desenvolvimento constante.
Toda sugestão ou feedback construtivo é muito bem-vindo! 🙌

2)
A função "Exportar para .CSV" salva o arquivo no diretório de output, proximo ao executavel do programa.
É necessário que o usuário, dentro do Excel ou outro programa apto para abrir o arquivo CSV, selecione a primeira coluna e va em "dados", alterando o modo de mostragem dos arquivos,
optando por selecionar "Texto para coluna", fazendo com que as colunas fiquem corretas.

