import sys

def counting(f):
  words = f.read()

  cnt = 0
  for _ in words.split(" "):
    cnt = cnt + 1

  return cnt


if __name__ == '__main__':
    
  
  if len(sys.argv) == 2:
    f = open(sys.argv[1])
    print(counting(f))
    f.close()
  
    