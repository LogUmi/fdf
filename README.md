<div align="center">
  <h1>fdf – Wireframe Renderer - 42 project</h1>
  <img src="./bin/fdf.png" />
  <br>
</div>

![Language](https://img.shields.io/badge/language-C-blue)
![Graphics](https://img.shields.io/badge/graphics-MiniLibX-orange)
![42](https://img.shields.io/badge/school-42-black)
![Status](https://img.shields.io/badge/status-completed-brightgreen)

> IN CONSTRUCTION ... TO BE IMPROVED
> **fdf** is a 3D wireframe map renderer built with **MiniLibX**.  
> It allows visualization of height maps (`.fdf` files) in **isometric projection** with zoom, rotation, and color gradients.

---

## 📖 Table of Contents
- [Description](#-description)
- [Features](#-features)
- [Installation](#-installation)
- [Usage](#-usage)
- [Examples](#-examples)
- [Roadmap](#-roadmap)
- [Credits](#-credits)
- [License](#-license)

---

## 📝 Description
`fdf` reads a map file (.fdf), containing elevation data, and displays it in a 3D wireframe using **MiniLibX**.  
This project introduces:  
- Graphics programming basics  
- Event handling (keyboard, mouse)  
- Isometric transformations  

---

## ✨ Features
- ✅ Load `.fdf` maps (2D arrays of integers).  
- ✅ Render wireframe in isometric projection.  
- ✅ Zoom in/out, translate the map.  
- ✅ Color gradients based on height.  

---

## ⚙️ Installation
Requirements:  
- Linux  
- `make` and `gcc`/`clang`

```bash
git clone https://github.com/LogUmi/fdf.git
cd fdf
make
```

---

## 🖥 Usage
```bash
./fdf maps/<map filename.fdf>
```

Controls:  
- `Arrows` → Move map  
- `+ / -` → Zoom  
- `R` → Reset  
- `ESC` → Exit  

---

## 📂 Project Structure

```
.
├── img/                # Content for README
├── includes/           # Header files (.h)
├── libft/				# Authorized functions
├── maps/				# Contains map files
├── mlx_linux/			# MiniLibX library
├── srcs/               # Source code (.c)
├── fr.subjectFdF.pdf	# Project subject
├── LICENSE			    # License MIT
├── Makefile
├── memento.odt			# Memo minilibx and math.h
└── README.md
```

---

## 🔎 Examples
TO COMPLETE

```bash
./fdf maps/42.fdf>
```

---

## 🚀 Roadmap
This project is the original version that was evaluated at 42 and will remain in this state.
- ✅ Rotate the map implemented in the project my fdf.  

---

## 👤 Credits
Project developed by **Loïc Gérard** – 📧 Contact: lgerard@studend.42perpignan.fr - [École 42 Perpignan](https://42perpignan.fr).

---

## 📜 License
This project is licensed under the MIT License. You are free to use, modify, and distribute it - see the [LICENSE](./LICENSE) file for details.

> ⚠️ **Note for students**  
> If you are a student at 42 (or elsewhere), it is strongly recommended **not to copy/paste** this code.  
> Instead, try to **write your own solution** — it’s the only way to really learn and succeed.