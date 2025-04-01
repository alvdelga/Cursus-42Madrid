 #!/bin/bash
 
#Colours
yellowColour="\e[0;33m\033[1m"
redColour="\e[0;31m\033[1m"

trap ctrl_c SIGINT

function ctrl_c(){

	echo -e "\n${yellowColour}[+]${endColour}${redColour} Saliendo...${endColour}"; sleep 2
}

 # Arquitectura y versión del kernel
 architecture=$(uname -a)
 
 # Número de núcleos físicos
 physical_cpu=$(cat /proc/cpuinfo | grep "physical id" | sort -u | wc -l)
 
 # Obtener el número de núcleos virtuales (hilos)
 virtual_cpu=$(cat /proc/cpuinfo | grep  processor | sort -u | wc -l)
 
 # Uso de memoria RAM y su porcentaje en megabytes
 mem_total=$(free --mega | awk '/Mem:/' | awk '{print $2}')
 mem_used=$(free --mega | awk '/Mem:/' | awk '{print $3}')
 mem_percentage=$(echo "scale=2; ($mem_used/$mem_total)*100" | bc)

 # Uso de disco y su porcentaje
 disk_total=$(df -h --total | awk '/total/' | awk '{print $2}')
 disk_used=$(df -h --total | awk '/total/' | awk '{print $3}')
 disk_percentage=$(df -h --total | awk '/total/' | awk '{print $5}')
 
 # CPU LOAD
 #cpul=$(vmstat 1 2 | tail -1 | awk '{printf $15}')
 #cpu_op=$(expr 100 - $cpul)
 #cpu_fin=$(printf "%.1f" $cpu_op)

 # Obtener la carga de CPU actual
 cpu_load=$(top -bn1 | grep "Cpu(s)" | awk -F '[,]' '{print 100 - $4 "%"}')
 
 # Obtener la fecha y hora del último reinicio
 last_boot=$(who -b | awk '{print $3 " " $4}')
 
 # Comprobar si LVM está activo
 lvm_active=$(lsblk | grep -q "lvm" && echo "yes" || echo "no")
 
 # Obtener el número de conexiones activas
 connections=$(ss -tun | grep ESTAB | wc -l)
 
 # Obtener el número de usuarios actualmente logueados
 users=$(who | awk '{print $1}' | sort -u | wc -l)
 
 # Obtener la dirección IPv4 y la MAC
 ip=$(hostname -I | awk '{print $1}')
 mac=$(ip link show | awk '/ether/ {print $2}')
 
 # Obtener el número de comandos ejecutados con sudo
 sudo_cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
 
 # Construir el mensaje
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
 #Sudo: $sudo_cmds cmd"
 
 # Mostrar el mensaje usando wall
 echo "$message" | wall
