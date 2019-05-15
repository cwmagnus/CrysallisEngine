import os, shutil, io, urllib.request, zipfile
from distutils.dir_util import copy_tree
from distutils.file_util import copy_file

DEPS_DIR = "Deps"
DEPS_INCLUDE_DIR = DEPS_DIR + "/include"
DEPS_LIB_DIR = DEPS_DIR + "/lib"
DEPS_TEMP_DIR = DEPS_DIR + "/temp"

VS_DEFAULT_YEAR = "2019"

GLFW_URL = "https://www.dropbox.com/s/3yqoxgpqzbbff6o/glfw-3.3.bin.WIN64.zip?dl=1"
GLAD_URL = "https://www.dropbox.com/s/5kv3pzx2fipfdb4/glad.zip?dl=1"
GLM_URL = "https://www.dropbox.com/s/xlp3pv6yjtq482q/glm-0.9.9.5.zip?dl=1"
STB_IMAGE_URL = "https://www.dropbox.com/s/mromcslmsu1cqvb/stb_image.h?dl=1"

# Removes old dependencies for reinstall
def remove_old_deps():
    if os.path.exists(DEPS_DIR):
        print("\nRemoving old dependencies...")
        shutil.rmtree(DEPS_DIR)
        print("Done")

# Download all dependencies
def download_deps():
    print("\nDownloading dependencies...")
    os.makedirs(DEPS_TEMP_DIR)

    download_dep(GLFW_URL, "glfw-3.3.bin.WIN64.zip")
    download_dep(GLAD_URL, "glad.zip")
    download_dep(GLM_URL, "glm-0.9.9.5.zip")
    download_dep(STB_IMAGE_URL, "stb_image.h")

    print("Done")   

# Download an individual dependency
def download_dep(url, filename):
    print("- Downloading " + filename + " from: " + url)
    request = urllib.request.urlopen(url)
    data = request.read()
    request.close()
    with open(DEPS_TEMP_DIR + '/' + filename, "wb") as f:
        f.write(data) 

# Unpack downloaded dependencies
def unpack_deps():
    print("\nUpacking dependencies...")

    unpack_dep("glfw-3.3.bin.WIN64.zip", "glfw-3.3.bin.WIN64")
    unpack_dep("glad.zip", "glad")
    unpack_dep("glm-0.9.9.5.zip", "glm-0.9.9.5")

    print("Done")

# Unpack an individual dependency
def unpack_dep(filename, output_dir):
    print("- Upacking " + filename + " to: " + output_dir)
    zip_ref = zipfile.ZipFile(DEPS_TEMP_DIR + '/' + filename, 'r')
    zip_ref.extractall(DEPS_TEMP_DIR + '/' + output_dir)
    zip_ref.close()

# Copy unpacked dependencies into the proper locations
def copy_deps():
    print("\nCopying dependencies...")

    # Copy GLFW files
    print("- Copying GLFW")
    copy_tree(DEPS_TEMP_DIR + "/glfw-3.3.bin.WIN64/glfw-3.3.bin.WIN64/include", DEPS_INCLUDE_DIR)
    copy_tree(DEPS_TEMP_DIR + "/glfw-3.3.bin.WIN64/glfw-3.3.bin.WIN64/lib-vc" + VS_DEFAULT_YEAR, DEPS_LIB_DIR)

    # Copy glad files
    print("- Copying glad")
    copy_tree(DEPS_TEMP_DIR + "/glad/include", DEPS_INCLUDE_DIR)

    # Copy glm files
    print("- Copying glm")
    copy_tree(DEPS_TEMP_DIR + "/glm-0.9.9.5/glm/glm", DEPS_INCLUDE_DIR + "/glm")

    # Copy stb image file
    print("- Copying stb image")
    copy_file(DEPS_TEMP_DIR + "/stb_image.h", DEPS_INCLUDE_DIR)
    

    print("Done")

# Remove temporary files
def remove_temp():
    if os.path.exists(DEPS_TEMP_DIR):
        print("\nRemoving temporary files...")
        shutil.rmtree(DEPS_TEMP_DIR)
        print("Done")


# Start installing routines
if __name__ == "__main__":
    print("Installing dependencies for CrysallisEngine...")
    remove_old_deps()
    download_deps()
    unpack_deps()
    copy_deps()
    remove_temp()
    print("\nFinished installing dependencies")
