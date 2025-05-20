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
- 📤 Exportação dos dados (função futura)
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
├── main.c         # Arquivo principal com o menu e chamadas de função
├── README.md      # Este arquivo
```

