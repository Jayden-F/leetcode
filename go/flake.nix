{
  description = "Go project";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs";
  };

  outputs =
    { self, nixpkgs, ... }@inputs:
    {
      devShells = {
        # Could do system-specific shells, here x86_64-linux as example:
        x86_64-linux =
          let
            pkgs = import nixpkgs { system = "x86_64-linux"; };
          in
          pkgs.mkShell {
            name = "leetcod-go";
            buildInputs = [
              pkgs.go_1_24
            ];

            shellHook = ''
              export GOPATH=$PWD/.gopath
              export GO111MODULE=on
              mkdir -p $GOPATH
            '';
          };
      };
    };
}
