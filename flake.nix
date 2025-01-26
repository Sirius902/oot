{
  description = "oot flake";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    flake-parts.url = "github:hercules-ci/flake-parts";
  };

  outputs = {
    self,
    flake-parts,
    ...
  } @ inputs:
    flake-parts.lib.mkFlake {inherit inputs;} {
      systems = [
        "x86_64-linux"
        "aarch64-linux"
        # FUTURE(Sirius902) darwin support?
      ];

      perSystem = {
        system,
        pkgs,
        ...
      }: {
        formatter = pkgs.alejandra;

        packages.ido-static-recomp-7_1 = pkgs.callPackage ./nix/ido-static-recomp/default.nix {
          ido-version = "7.1";
        };

        packages.ido-static-recomp-5_3 = pkgs.callPackage ./nix/ido-static-recomp/default.nix {
          ido-version = "5.3";
        };

        devShells.default = pkgs.mkShell {
          buildInputs = [
            pkgs.gnumake
            pkgs.python3
            pkgs.libpng
            pkgs.libxml2

            pkgs.pkgsCross.mips-linux-gnu.buildPackages.binutils
          ];

          CC_IDO = "${self.packages.${system}.ido-static-recomp-7_1}/bin/cc";
          CC_OLD_IDO = "${self.packages.${system}.ido-static-recomp-5_3}/bin/cc";
          NO_CURL = 1;

          MIPS_BINUTILS_PREFIX = "mips-unknown-linux-gnu-";
        };
      };
    };
}
