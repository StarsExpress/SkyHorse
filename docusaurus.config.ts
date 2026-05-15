import {themes as prismThemes} from 'prism-react-renderer';
import type {Config} from '@docusaurus/types';
import type * as Preset from '@docusaurus/preset-classic';
import remarkMath from 'remark-math';
import rehypeKatex from 'rehype-katex';

// This runs in Node.js - Don't use client-side code here (browser APIs, JSX...)

const config: Config = {
  title: '天码行空 SkyHorse',
  tagline: '天马行空的思路 天天专注想代码',
  favicon: 'img/favicon.ico',

  // Future flags, see https://docusaurus.io/docs/api/docusaurus-config#future
  future: {
    v4: true, // Improve compatibility with the upcoming Docusaurus v4
  },

  // Set the production url of your site here
  url: 'https://starsexpress.github.io',
  // Set the /<baseUrl>/ pathname under which your site is served
  // For GitHub pages deployment, it is often '/<projectName>/'
  baseUrl: '/SkyHorse/',

  // GitHub pages deployment config.
  // If you aren't using GitHub pages, you don't need these.
  organizationName: 'StarsExpress', // Usually your GitHub org/user name.
  projectName: 'SkyHorse', // Usually your repo name.

  onBrokenLinks: 'throw',

  i18n: {
    defaultLocale: 'en',
    locales: ['en', 'zh-Hans'],
    localeConfigs: {
      'en': { label: 'English' },
      'zh-Hans': { label: '简体中文' },
    },
  },

  presets: [
    [
      'classic',
      {
        docs: {
          sidebarPath: './sidebars.ts',
          numberPrefixParser: false, // Do not remove number prefixes. Very important.
          routeBasePath: 'docs',
          remarkPlugins: [remarkMath], // For LaTeX.
          rehypePlugins: [rehypeKatex],
        },
        blog: {
          showReadingTime: true,
          feedOptions: {
            type: ['rss', 'atom'],
            xslt: true,
          },
          // Useful options to enforce blogging best practices.
          onInlineTags: 'warn',
          onInlineAuthors: 'warn',
          onUntruncatedBlogPosts: 'warn',
        },
        theme: {
          customCss: './src/css/custom.css',
        },
      } satisfies Preset.Options,
    ],
  ],

  plugins: [
  () => ({
    name: 'raw-loader-plugin',
    configureWebpack() {
      return {
        module: {
          rules: [
            {
              resourceQuery: /raw/,
              type: 'asset/source',
            },
          ],
        },
      };
    },
  }),
],

  stylesheets: [ // For LaTeX.
    {
      href: 'https://cdn.jsdelivr.net/npm/katex@0.13.24/dist/katex.min.css',
      type: 'text/css',
    },
  ],

  themeConfig: {
    // Replace with your project's social card.
    image: 'img/logo.jpg',
    colorMode: {
      respectPrefersColorScheme: true,
    },
    navbar: {
      title: '天码行空 SkyHorse',
      logo: {
        alt: '天码行空 SkyHorse Logo',
        src: 'img/logo.jpg',
      },
      items: [
        {
          type: 'docSidebar',
          sidebarId: 'tutorialSidebar',
          position: 'left',
          label: 'LeetCode目录📒',
        },
        {
          to: '/about',
          label: '码主二三事👀',
          position: 'left',
        },
        {
          // Link to the directory for direct code scripts lookup.
          href: 'https://github.com/StarsExpress/SkyHorse',
          label: 'SkyHorse Repo',
          position: 'right',
        },
        {
          type: 'localeDropdown',
          position: 'right'
        },
      ],
    },
    footer: {
      style: 'dark',
      links: [],
      copyright: `Copyright © ${new Date().getFullYear()} 天码行空 SkyHorse. Built with Docusaurus.`,
    },
    prism: {
      theme: prismThemes.github,
      darkTheme: prismThemes.dracula,
    },
  } satisfies Preset.ThemeConfig,
};

export default config;
