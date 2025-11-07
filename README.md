# Compile and Run Your Game with Docker (Linux) — GUI

Run the following commands from your project root:
⚠️ Note: This setup relies on X11 for GUI output. Pure Wayland sessions might not display correctly.

```bash
# 1. Build the Docker image
sudo docker build --no-cache -t mygame .

# 2. Allow Docker to access your X11 display
xhost +local:docker

# 3. Run the game with GUI
sudo docker run --rm \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    mygame
