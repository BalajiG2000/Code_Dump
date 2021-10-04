# Merge Sort in Ruby

print "How many numbers would you like to sort?\n"
input = gets.chomp.to_i

if input == 1
  return [1]
end

array_to_sort = []
input.times do
  array_to_sort << rand(0..99)
end

def merge_sort(numbers)
  if numbers.length <= 1
    return numbers
  end
  split_point = (numbers.length / 2).round
  left_array = numbers.take(split_point)
  sorted_left_array = merge_sort(left_array)
  right_array = numbers.drop(split_point)
  sorted_right_array = merge_sort(right_array)
  merge(sorted_left_array, sorted_right_array)
end

def merge(left, right)
  if right.empty?
    return left
  elsif left.empty?
    return right
  end
  small_sort = if left[0] <= right[0]
    left.shift
  else
    right.shift
  end
  sorted = merge(left, right)
  print "#{[small_sort] + sorted} \n"
  [small_sort] + sorted
end

print merge_sort(array_to_sort)
