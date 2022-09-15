https://blog.csdn.net/nothk/article/details/111610009


pull a image [alpine/git]
run a image and create a container [repo]
cp a container to another place [getting-started]

```
docker run --name repo alpine/git clone https://github.com/docker/getting-started.git
docker cp repo:/git/gitting-started/ .
```

build a image [docker101tutorial]

```
cd getting-started
docker build -t docker101tutorial .
```

run your container
```
docker run -d -p 80:80 --name docker-tutorial docker101tutorial
```