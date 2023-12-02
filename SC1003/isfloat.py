def isfloat(num):
  try:
    float(num)
    return True
  except ValueError:
    return False

a = "i"
print(isfloat(a))
