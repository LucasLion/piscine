find . -type f -iname '*.sh' -exec basename {} \; | rev | cut -c 4- | rev

