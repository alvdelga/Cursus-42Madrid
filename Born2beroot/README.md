# 🛡️ Born2beroot

**Born2beroot** es un proyecto del campus 42 cuyo objetivo es configurar un servidor Linux virtual desde cero siguiendo una serie de requisitos estrictos de seguridad y administración. Fue realizado en entorno Debian y virtualizado con VirtualBox.

![Success Score](./image.png)

---

## 🎯 Objetivos del proyecto

- Configurar un servidor Linux (Debian o Rocky Linux).
- Uso obligatorio de particiones cifradas con LVM.
- Configurar usuarios, grupos y políticas de contraseñas fuertes.
- Configurar firewall (UFW o firewalld).
- Activar AppArmor o SELinux según distribución.
- Instalar y asegurar el acceso por SSH (puerto 4242).
- Evitar acceso SSH al usuario root.
- Implementar script `monitoring.sh` para mostrar estadísticas del sistema.

---

## ⚙️ Script `monitoring.sh`

El script muestra información del sistema cada 10 minutos usando `cron` y `wall`. Algunos de los datos que imprime:

- Arquitectura del sistema y versión del kernel
- Número de CPUs físicos y virtuales
- Uso de memoria RAM y disco
- Carga actual de CPU
- Fecha del último reinicio
- Uso de LVM
- Número de conexiones TCP activas
- Usuarios conectados
- Dirección IP y MAC
- Número de comandos ejecutados con `sudo`

Ejemplo de salida:
```bash
#Architecture: Linux malvarde 6.1.0-18-amd64 x86_64
#CPU physical: 1
#vCPU: 2
#Memory Usage: 512 / 2048 MB (25.00%)
#Disk Usage: 20G / 8G (40%)
#CPU load: 5.5 %
#Last boot: 2024-04-01 08:42
#LVM use: yes
#TCP Connections: 3 ESTABLISHED
#User log: 2
#Network: IP 10.0.2.15 (08:00:27:xx:xx:xx)
#Sudo: 42 cmd
```

---
```bash
📜 Script de Monitorización
🕑 Este script está configurado con `cron` para ejecutarse automáticamente cada 10 minutos mostrando el estado del sistema mediante `wall`.

#!/bin/bash

# Colours
yellowColour="\e[0;33m\033[1m"
redColour="\e[0;31m\033[1m"

trap ctrl_c SIGINT

function ctrl_c(){
    echo -e "\n${yellowColour}[+]${endColour}${redColour} Saliendo...${endColour}"
    sleep 2
}

# Arquitectura y versión del kernel
architecture=$(uname -a)

# Número de núcleos físicos
physical_cpu=$(cat /proc/cpuinfo | grep "physical id" | sort -u | wc -l)

# Número de núcleos virtuales (hilos)
virtual_cpu=$(cat /proc/cpuinfo | grep processor | sort -u | wc -l)

# Memoria RAM usada
mem_total=$(free --mega | awk '/Mem:/' | awk '{print $2}')
mem_used=$(free --mega | awk '/Mem:/' | awk '{print $3}')
mem_percentage=$(echo "scale=2; ($mem_used/$mem_total)*100" | bc)

# Uso de disco
disk_total=$(df -h --total | awk '/total/' | awk '{print $2}')
disk_used=$(df -h --total | awk '/total/' | awk '{print $3}')
disk_percentage=$(df -h --total | awk '/total/' | awk '{print $5}')

# Carga de CPU
cpu_load=$(top -bn1 | grep "Cpu(s)" | awk -F '[,]' '{print 100 - $4 "%"}')

# Último reinicio
last_boot=$(who -b | awk '{print $3 " " $4}')

# LVM
lvm_active=$(lsblk | grep -q "lvm" && echo "yes" || echo "no")

# Conexiones activas
connections=$(ss -tun | grep ESTAB | wc -l)

# Usuarios logueados
users=$(who | awk '{print $1}' | sort -u | wc -l)

# Dirección IP y MAC
ip=$(hostname -I | awk '{print $1}')
mac=$(ip link show | awk '/ether/ {print $2}')

# Comandos sudo ejecutados
sudo_cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

# Mensaje
message="
#Architecture: $architecture
#CPU physical: $physical_cpu
#vCPU: $virtual_cpu
#Memory Usage: $mem_used / ${mem_total} MB ($mem_percentage%)
#Disk Usage: $disk_total / $disk_used ($disk_percentage)
#CPU load: $cpu_load
#Last boot: $last_boot
#LVM use: $lvm_active
#TCP Connections: $connections ESTABLISHED
#User log: $users
#Network: IP $ip ($mac)
#Sudo: $sudo_cmds cmd
"

echo "$message" | wall

```

## 📸 Resultado

![Nota final 125/100](./image.png)

---

## 🧑‍💻 Autor

**👨‍💻 alvdelga** - Estudiante en 42 Madrid  
[GitHub Profile](https://github.com/alvdelga)

---

## ✅ Estado del proyecto

> Proyecto completado con éxito y nota **125/100**