```sh
docker build . -t riscvback
docker run -it --rm -v $(pwd):/app riscvback /bin/bash
```
