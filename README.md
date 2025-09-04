<div align="center">
  <h1>fdf – 42 project Wireframe Renderer</h1>
  <img src="./img/fdf.png" />
  <br>
</div>

![Language](https://img.shields.io/badge/language-C-blue)
![Graphics](https://img.shields.io/badge/graphics-MiniLibX-orange)
![42](https://img.shields.io/badge/school-42-black)
![Status](https://img.shields.io/badge/status-completed-brightgreen)

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
- MiniLibX for Linux needs the dependencies `xorg`, `libxext-dev` and `zlib1g-dev`.

if needed you can install the MinilibX depencies with:
```bash
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```
Then:
```bash
git clone https://github.com/LogUmi/fdf.git
cd fdf
make
```
This will generate an excutable fdf.

---

## 🖥 Usage
```bash
./fdf maps/<map filename.fdf>
```

Controls:  
- `Arrows` → Move map  
- `+ / -` → Zoom  
- `SPACE` → Reset  
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

```bash
$ ./fdf maps/42.fdf
Special feature detected and applied
Loading map ... done
Applying this fdf colors defintion (no colors in map)
Screen 1920x1200 detected
Windows 1064x1064 opended
```
<img height="750" src="./img/fdf1.png"/>

```bash
Regular end of session on esc key press
```
Other screen outputs:

<img height="750" src="./img/fdf2.png"/>
You can move or zoom the wireframe:
<img height="750" src="./img/fdf3.png"/>

<img height="750" src="./img/fdf0.png"/>

<img height="750" src="./img/fdf4.png"/>

---

## 🚀 Roadmap
This project is the original version that was evaluated at 42 and will remain in this state.
- ✅ Rotate the map implemented in the project my fdf.  

---

## 👤 Credits
Project developed by **Loïc Gérard** – 📧 Contact: lgerard@studend.42perpignan.fr - [École 42 Perpignan](https://42perpignan.fr).

---

## 📜 License
- The project code (FdF, MiniRT, etc.) is released under the MIT License.
- The included MiniLibX library is released under the BSD License (© Olivier Crouzet, 1999–2015).
Both licenses are provided in the [LICENSE](./LICENSE) file of this repository.

> ⚠️ **Note for students**  
> If you are a student at 42 (or elsewhere), it is strongly recommended **not to copy/paste** this code.  
> Instead, try to **write your own solution** — it’s the only way to really learn and succeed.
