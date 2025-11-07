FROM ubuntu:latest

# Install all build dependencies for SFML + CA certificates for git
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    git \
    pkg-config \
    ca-certificates \
    libx11-dev \
    libxi-dev \
    libxrandr-dev \
    libxcursor-dev \
    libxinerama-dev \
    libxext-dev \
    libxrender-dev \
    libgl1-mesa-dev \
    libopenal-dev \
    libudev-dev \
    libfreetype6-dev \
    libvorbis-dev \
    libogg-dev \
    libflac-dev \
 && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

# Build the project
RUN mkdir build && cd build && cmake .. && make

# Run the game
CMD ["./build/game"]
