To compile with docker(Linux)
```sudo docker build --no-cache -t mygame .```
```xhost +local:docker```
```sudo docker run --rm -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix mygame```
