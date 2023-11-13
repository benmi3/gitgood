class Solution:
    def trap(self, height: list[int]) -> int:
        water_level = 0
        check_ = self.thinking_box(height)
        amount_of_water = 0
        for index, item in enumerate(check_):
            if True in item:
                amount_of_water = (
                    amount_of_water
                    + self.thinking_outside(item)
                )
        return amount_of_water

    def thinking_box(self, h_: list[int]) -> list[bool]:
        list_clone = h_
        list_looper = False
        list_of_bools = []
        while not list_looper:
            internal_list = []
            for index_, item in enumerate(list_clone):
                if item == 0:
                    internal_list.append(False)
                else:
                    internal_list.append(True)
                    list_clone[index_] = item - 1
            list_of_bools.append(internal_list)
            if True not in internal_list:
                list_looper = True
        return list_of_bools

    def thinking_outside(self, h_: list[bool]) -> int:
        wall_finder = []
        between_walls = []
        for index, item in enumerate(h_):
            if item:
                wall_finder.append(index)
        wall_finder.sort()
        for index, item in enumerate(h_):
            if not item:
                if wall_finder[0] < index:
                    if index < wall_finder[-1]:
                        if index not in between_walls:
                            between_walls.append(index)

        return len(between_walls)


if __name__ == "__main__":
    height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]  # this should return 6
    height = [4, 2, 0, 3, 2, 5]                    # this should return 9
    s = Solution()
    water_level = s.trap(height)
    print(f"---Finished measuring---\nWater Level = {water_level}")
